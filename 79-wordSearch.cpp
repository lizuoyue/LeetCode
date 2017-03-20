class Solution {
public:
	vector< vector<bool> > visited;
	bool exist(vector< vector<char> > &board, string word) {
		int m = board.size(), n = board[0].size();
		vector< pair<int, int> > start;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == word[0]) {
					start.push_back(make_pair(i, j));
				}
			}
		}
		visited.clear();
		visited.resize(m, vector<bool>(n, false));
		for (int i = 0; i < start.size(); ++i) {
			if (dfs(board, start[i], word, 0)) {
				return true;
			}
		}
		return false;
	}

	bool dfs(vector< vector<char> > &board,
		pair<int, int> start, string word, int id) {

		int a = start.first, b = start.second;
		visited[a][b] = true;

		++id;
		if (id == word.length()) {
			visited[a][b] = false;
			return true;
		}

		if ((a > 0) && (word[id] == board[a - 1][b]) && !visited[a - 1][b]) {
			if (dfs(board, make_pair(a - 1, b), word, id)) {
				visited[a][b] = false;
				return true;
			}
		}
		if ((a < board.size() - 1) && (word[id] == board[a + 1][b]) && !visited[a + 1][b]) {
			if (dfs(board, make_pair(a + 1, b), word, id)) {
				visited[a][b] = false;
				return true;
			}
		}
		if ((b > 0) && (word[id] == board[a][b - 1]) && !visited[a][b - 1]) {
			if (dfs(board, make_pair(a, b - 1), word, id)) {
				visited[a][b] = false;
				return true;
			}
		}
		if ((b < board[0].size() - 1) && (word[id] == board[a][b + 1]) && !visited[a][b + 1]) {
			if (dfs(board, make_pair(a, b + 1), word, id)) {
				visited[a][b] = false;
				return true;
			}
		}
		visited[a][b] = false;
		return false;
	}
};