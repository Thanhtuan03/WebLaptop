#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Ð?nh nghia m?t c?u trúc nút trong d? th?
struct Node {
    int id;
    int heuristic;
    int cost;
    vector<int> path;

    // Constructor
    Node(int _id, int _heuristic, int _cost, const vector<int>& _path) : id(_id), heuristic(_heuristic), cost(_cost), path(_path) {}
};

// Hàm heuristic
int heuristicFunction(int fromNode, int toNode) {
    // Tr? v? giá tr? heuristic t? nút hi?n t?i d?n nút dích
    // C?n du?c tri?n khai d?a trên bài toán c? th?
    return 0;
}

// Hàm so sánh uu tiên cho hàng d?i uu tiên
struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        // So sánh theo t?ng chi phí và giá tr? heuristic
        return (a.cost + a.heuristic) > (b.cost + b.heuristic);
    }
};

// Hàm A* Search
void aStarSearch(const vector<vector<int> >& graph, int startNode, int goalNode) {
    int numNodes = graph.size();

    // T?o hàng d?i uu tiên d? luu tr? các nút c?n xét
    priority_queue<Node, vector<Node>, CompareNodes> pq;

    // T?o nút ban d?u
    vector<int> initialPath;
    initialPath.push_back(startNode);
    Node initialNode(startNode, heuristicFunction(startNode, goalNode), 0, initialPath);

    // Thêm nút ban d?u vào hàng d?i uu tiên
    pq.push(initialNode);

    // M?ng d? theo dõi các nút dã xét
    vector<bool> visited(numNodes, false);
    visited[startNode] = true;

    while (!pq.empty()) {
        // L?y nút có uu tiên cao nh?t t? hàng d?i uu tiên
        Node currentNode = pq.top();
        pq.pop();

        // Ki?m tra n?u dây là nút dích
        if (currentNode.id == goalNode) {
            cout << "Da tim thay dich." << endl;
            cout << "Duong di tu " << startNode << " den " << goalNode << ": ";
            for (int node : currentNode.path) {
                cout << node << " ";
            }
            cout << endl;
            return;
        }

        // Xét các nút k? c?a nút hi?n t?i
        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (graph[currentNode.id][neighbor] != 0 && !visited[neighbor]) {
                // T?o nút m?i v?i thông tin c?a nút k?
                vector<int> newPath = currentNode.path;
                newPath.push_back(neighbor);
                Node neighborNode(neighbor, heuristicFunction(neighbor, goalNode), currentNode.cost + graph[currentNode.id][neighbor], newPath);

                // Thêm nút k? vào hàng d?i uu tiên
                pq.push(neighborNode);

                // Ðánh d?u nút k? là dã xét
                visited[neighbor] = true;
            }
        }
    }

    // N?u không tìm th?y du?ng di d?n dích
    cout << "khong tim thay duong den dich." << endl;
}

int main() {
    // Kh?i t?o d? th? (ma tr?n k?)
    vector<vector<int>> graph = {
        {0, 7, 0, 3, 0 ,0},
        {7, 0, 3, 0, 0 ,0},
        {0, 3, 0, 0, 0 ,0},
        {3, 0, 0, 0, 4, 5},
        {0, 0, 0, 5, 0 ,0},
        {0, 0, 0, 5, 0 ,0}
    };
    cout << "Nhap dinh bat dau: ";
    int startNode = 0;
    cin >> startNode;
    cout << "Nhap dinh ket thuc: ";
    int goalNode = 0; // Ð?nh k?t thúc
    cin >> goalNode;
    aStarSearch(graph, startNode, goalNode);
    return 0;
}