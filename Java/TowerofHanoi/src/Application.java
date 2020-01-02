import java.util.ArrayList;
import java.util.Scanner;

public class Application {
	public static void main(String[] args) {

		GameManager gm1 = new GameManager();
		gm1.draw();

		for (;;) {

			Scanner scanner = new Scanner(System.in);
			System.out.println("What tower would you like to move from: ");
			int from = scanner.nextInt();

			Scanner scanner1 = new Scanner(System.in);
			System.out.println("What tower would you like to move to: ");
			int to = scanner1.nextInt();

			if (from == 0 && to == 0) {
				break;
			} else {
				try {
					gm1.move(from - 1, to - 1);
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
			}

		}
		
		System.out.println("Thanks For Playing! ");

	}

}
