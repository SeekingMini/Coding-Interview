/*
 * 题目：矩阵中的路径
 * 链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 */
 
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool dfs(vector<vector<char>>& board, int r, int c, const string& word, int start) {
	// 越界或者碰到已经访问过的或者字符不相等
	if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[start]) return false;
	// 扫描到word最后一个字符
	if (start == word.length() -1) return true;
		
	char temp = board[r][c];	
	board[r][c] = '\0';
	if (dfs(board, r + 1, c, word, start + 1) ||
	    dfs(board, r - 1, c, word, start + 1) ||
	    dfs(board, r, c + 1, word, start + 1) ||
	    dfs(board, r, c - 1, word, start + 1)
	) return true;
	board[r][c] = temp;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	if (word.empty()) return false;
	
	const int row = board.size();
	const int col = board[0].size();
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) 
			if (dfs(board, i, j, word, 0)) return true;
	}
	
	return false;
}

int main() {
	int row, col;
	string word;
	vector<vector<char>> board;
	
	// 输入
	cin >> word;
	cin >> row >> col;
	for (int r = 0; r < row; r++) {
		char c;
		vector<char> oneRow;
		while (cin >> c) {
			oneRow.push_back(c);
			
			if (getchar() == '\n') break;
		}
		board.push_back(oneRow);
	}
	
	// 判断路径是否存在
	bool flag = exist(board, word);
	cout << flag << endl;
	
	return 0;
}