char *strstr(const char *str1, const char *str2)
{
    char *cp = (char*)str1;
    char *s1, *s2;

    if (!*str2)
        return((char *)str1);

    while (*cp)
    {
        s1 = cp;
        s2 = (char *)str2;

        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;

        if (!*s2)
            return(cp);

        cp++;
    }
    return(NULL);
}

/*
由于回文分为偶回文（比如 bccb）和奇回文（比如 bcacb），
而在处理奇偶问题上会比较繁琐，所以这里我们使用一个技巧，
在字符间插入一个字符（前提这个字符未出现在串里）。
举个例子：s="abbahopxpo"，转换为s_new="$#a#b#b#a#h#o#p#x#p#o#"（这里的字符 &dollar; 
只是为了防止越界，下面代码会有说明），如此，s 里起初有一个偶回文abba和一个奇回文opxpo，
被转换为#a#b#b#a#和#o#p#x#p#o#，长度都转换成了奇数。
*/
 
char s[1000];
char s_new[2000];
int p[2000];
 
int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';  //别忘了哦  
 
    return j;  //返回s_new的长度  
}
 
int Manacher()
{
    int len = Init();  //取得新字符串长度并完成向s_new的转换  
    int maxLen = -1;   //最长回文长度  
    int id;
    int mx = 0;
 
    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);  //需搞清楚上面那张图含义, mx和2*id-i的含义
        else
            p[i] = 1;
        while (s_new[i - p[i]] == s_new[i + p[i]])  //不需边界判断，因为左有'$',右有'\0'  
            p[i]++;
        if (mx < i + p[i])  //我们每走一步i，都要和mx比较，我们希望mx尽可能的远，这样才能更有机会执行if (i < mx)这句代码，从而提高效率  
        {
            id = i;
            mx = i + p[i];
        }
        maxLen = max(maxLen, p[i] - 1);
    }
    return maxLen;
}
