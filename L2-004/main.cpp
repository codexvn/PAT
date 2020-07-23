#include<iostream>

using namespace std;

class TreeClass {
public:
    char mod2 = 0;
    int *data, N;
    struct Node {
        int root;
        Node *L_node = NULL, *R_node = NULL;
    } *tree=NULL;
    void InitTreeMod1(Node *&this_node, int flag) {
        if (this_node == NULL) {
            this_node = new Node{data[flag],NULL,NULL};
            return;
        }
        if (this_node->root > data[flag])
            InitTreeMod1(this_node->L_node,flag);
        else if (this_node->root <= data[flag])
            InitTreeMod1(this_node->R_node,flag);
    }
    void InitTreeMod2(Node *&this_node, int flag) {
        if (this_node == NULL) {
            this_node = new Node{data[flag],NULL,NULL};
            return;
        }
        if (this_node->root > data[flag])
            InitTreeMod2(this_node->R_node,flag);
        else if (this_node->root <= data[flag])
            InitTreeMod2(this_node->L_node,flag);
    }
    void PrintTree(Node *&this_node) {
        if (this_node == NULL)
            return;
        else {
            PrintTree(this_node->L_node);
            PrintTree(this_node->R_node);
            cout<<this_node->root<<" ";
        }
    }

    TreeClass(int n) {
        this->N = n;
        if (n == 1) { //只有一个节点
            int tmp;
            cin >> tmp;
            cout <<"YES"<<endl<<tmp<<endl;
        } else {
            data = new int[n];
            cin >> data[0] >> data[1];
            int flag = 2;
            int status = data[0] <= data[1] ? 1 : 2;//如果下一个子树的根节点大于等于root,则进入状态1，否则状态2
            while (flag < n) {
                switch (status) {
                    case 1: {
                        cin >> data[flag];
                        if (data[flag] < data[0]) {
                            mod2 = 1;
                            status = 3;
                        }
                        break;
                    };
                    case 2: {
                        cin >> data[flag];
                        if (data[flag] >= data[0])
                            status = 4;
                        break;
                    };
                    case 3: {
                        cin >> data[flag];
                        if (data[flag] >= data[0])
                            status = 5;
                        break;
                    };
                    case 4: {
                        cin >> data[flag];
                        if (data[flag] < data[0])
                            status = 5;
                        break;
                    };
                    case 5: {
                        cout << "NO" << endl;
                        flag = n;
                        return;
                    };
                }
                flag++;
            }  //5个状态的有限状态机
            if (mod2 == 0)
                for (int i = 0; i <this->N ; ++i)
                    this->InitTreeMod1(this->tree,i);
            else
                for (int i = 0; i <this->N ; ++i)
                    this->InitTreeMod2(this->tree,i);

            cout <<"YES"<<endl;
            PrintTree(tree->L_node);
            PrintTree(tree->R_node);
            cout<<tree->root<<endl;
        }
    }
};
int main() {
    int N;
    cin>>N;
    TreeClass my_tree(N);
}