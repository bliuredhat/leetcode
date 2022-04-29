#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ZSKIPLIST_MAXLEVEL 32 /* Should be enough for 2^64 elements */
#define ZSKIPLIST_P 0.25      /* Skiplist P = 1/4 */

typedef char *sds;

typedef struct zskiplistNode {
    sds ele;
    double score;
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned long span;
    } level[];
} zskiplistNode;

typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;

zskiplist *zslCreate(void);

void zslFree(zskiplist *zsl);

zskiplistNode *zslInsert(zskiplist *zsl, double score, sds ele);

int zslDelete(zskiplist *zsl, double score, sds ele, zskiplistNode **node);

zskiplistNode *zslFirstInLexRange(zskiplist *zsl, zlexrangespec *range);

zskiplistNode *zslLastInLexRange(zskiplist *zsl, zlexrangespec *range);


