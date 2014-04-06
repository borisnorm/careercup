// http://www.careercup.com/question?id=5649647234187264
// i for row, j for column, color represented as integer id.
// 0 for white, 1 for black.
void draw(int i, int j, int color);

void drawChessBoard() {
	int i;
	
	/*
		b w b w b w b w
		w b w b w b w b
		b w b w b w b w
		w b w b w b w b
		b w b w b w b w
		w b w b w b w b
		b w b w b w b w
		w b w b w b w b
	*/
	
	for (i = 0; i < 64; ++i) {
		draw(i >> 3, i & 7, i + 1 & 1);
	}
}