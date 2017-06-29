
struct TNode {
    int info;
    struct TNode *left, *right;
};

typedef struct TNode TNode;

struct LNode {
    int info;
    struct LNode *next;
};

typedef struct LNode LNode;

struct LLNode {
    struct LNode *info;
    struct LLNode *next;
};

typedef struct LLNode LLNode;