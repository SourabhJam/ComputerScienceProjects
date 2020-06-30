import java.util.Scanner;

public class Application {

	public static void main(String[] args) {

		int firstNum = 0;
		int secondNum = 1;
		int newNum;

		for (int i = 0; i < 9; i++) {
			newNum = firstNum + secondNum;
			System.out.print(" " + newNum);
			firstNum = secondNum;
			secondNum = newNum;
		}

	}

}
