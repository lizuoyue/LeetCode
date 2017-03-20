class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int cover;
		if (A >= G || B >= H || C <= E || D <= F) {
			cover = 0;
		} else {
			int left = max(A, E), right = min(C, G);
			int up = min(D, H), down = max(B, F);
			cover = (right - left) * (up - down);
		}
		return (C - A) * (D - B) + (G - E) * (H - F) - cover;
	}
};