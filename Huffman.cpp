
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Dinh nghia cau truc Node cho cay Huffman
// Node se chua ky tu, tan so xuat hien cua ky tu, con trai va con phai
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

// Tao mot Node moi voi cac tham so truyen vao

Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// So sanh hai Node dua tren tan so xuat hien cua chung

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Ham xay dung cay Huffman va luu tru ma Huffman cho moi ky tu

void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    // Neu gap Node la
    
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Giai ma chuoi Huffman thanh chuoi ban dau


void decode(Node* root, int &index, string str) {
    if (root == nullptr) {
        return;
    }

    // Nếu gặp Node lá
    if (!root->left && !root->right) {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

// Xây dựng cây Huffman và mã hóa chuỗi


void buildHuffmanTree(string text) {
    // Đếm tần số xuất hiện của các ký tự và lưu vào bảng băm
    
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Tạo một hàng đợi ưu tiên để lưu cây Huffman
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Tạo một Node lá cho mỗi ký tự và thêm vào hàng đợi ưu tiên
    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // Lặp cho đến khi còn duy nhất một Node trong hàng đợi
    while (pq.size() != 1) {
        // Lấy hai Node có tần số nhỏ nhất từ hàng đợi
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Tạo một Node mới với tổng tần số của hai Node trên
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // Node gốc của cây Huffman
    Node* root = pq.top();

    // Lưu mã Huffman cho từng ký tự
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    //In ra
    cout << "Ma Huffman la:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nChuoi ban dau\n" << text << '\n';

    // In ra chuỗi Huffman mã hóa
    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nChuoi sau khi ma hoa:\n" << str << '\n';

    // Giải mã lại chuỗi Huffman
    int index = -1;
    cout << "\nChuoi sau khi giai ma\n";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
    cout << '\n';
}

int main() {
    cout<<"Nhap chuoi: ";
    string text;
    getline(cin, text);
    buildHuffmanTree(text);


    
    return 0;
}
