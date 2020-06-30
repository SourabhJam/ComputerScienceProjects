import java.awt.Color;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Application {

	private static Graphics g;

	public static void main(String[] args) throws IOException {
		JFrame frame = new JFrame("Game");
		frame.setSize(1500, 1000);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		GridLayout layout = new GridLayout(2, 1);
		frame.setLayout(layout);

		// TowerPanel tPanel = new TowerPanel();
		// frame.add(tPanel);
		
		GameManager gm1 = new GameManager();
		frame.add(gm1);

		OperationPanel opPanel = new OperationPanel();
		frame.add(opPanel);
		
		

		frame.setVisible(true);

	}
}
