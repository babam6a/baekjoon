#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    struct Node {
        int parent;
        vector<int> children;
    };

    struct Node nodes[50];

    int N;
    int root = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        nodes[i].parent = p;

        if (p != -1) {
            struct Node *p_node = &nodes[p];
            p_node->children.push_back(i);
        }
        else {
            root = i;
        }
    }

    int d;
    cin >> d;
    struct Node *del_node = &nodes[d];

    if (del_node -> parent == -1) {
        cout << 0;
        return 0;
    }

    struct Node *parent_node = &nodes[del_node -> parent];

    for (auto it = parent_node -> children.begin(); it != parent_node -> children.end(); it++) {
        if (*it == d) {
            parent_node -> children.erase(it);
            break;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << nodes[i].parent << " ";
    //     cout << "[";
    //     for (auto it = nodes[i].children.begin(); it != nodes[i].children.end(); it++) {
    //         cout << *it << " ";
    //     }
    //     cout << "]" << "\n";
    // }

    queue<int> q;
    int result = 0;

    q.push(root);

    while (!q.empty()) {
        struct Node *target = &nodes[q.front()];
        // cout << q.front() << " ";
        q.pop();

        vector<int> children = target -> children;

        if (children.empty()) {
            result++;
            continue;
        }

        for (auto it = children.begin(); it != children.end(); it++) {
            q.push(*it);
        }
    }

    cout << result;
}