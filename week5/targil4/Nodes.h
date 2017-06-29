
struct HNode {
    char chr;
    struct HNode *left, *right;
};

typedef struct HNode HNode;

struct Symbol {
    char chr;
    int counter;
};

typedef struct Symbol Symbol;