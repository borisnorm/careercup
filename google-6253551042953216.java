// http://www.careercup.com/question?id=6253551042953216
public class Test {
	static int res_count = 0;
	
	public static void main(String [] args) {
		printParenthesis(3);
	}
	
	public static void printParenthesis(int n) {
		char buffer[] = new char[n * 2];
		res_count = 0;
		printP(buffer, 0, n, 0, 0);
	}
	
	public static void printP(char buffer[], int index, int n, int open, int close) {
		if(close == n) {
			System.out.print((++res_count) + ".");
			System.out.println(new String(buffer));
		} else {
			if (open > close) {
				buffer[index] = ']';
				printP(buffer, index+1, n, open, close + 1);
			}
			if (open < n) {
				buffer[index] = '[';
				printP(buffer, index + 1, n, open + 1, close);
			}
		}
	}
}