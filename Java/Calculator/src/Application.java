import java.awt.*;
import javax.swing.*;

public class Application {

	public static void main(String[] args) {

		JFrame frame = new JFrame("Calculator");
		frame.setSize(1000, 1000);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		GridLayout layout = new GridLayout(2,2);
		frame.setLayout(layout);
		
		ResultPanel resultPanel = new ResultPanel();
		frame.add(resultPanel);
		
		JPanel dummyPanel = new JPanel();
		frame.add(dummyPanel);
		
		NumberPanel numberPanel = new NumberPanel(resultPanel);
		numberPanel.setBackground(Color.BLACK);
		frame.add(numberPanel); 
		
		OperationalPanel opPanel = new OperationalPanel();
		frame.add(opPanel);
		
		frame.setVisible(true);
	}
}