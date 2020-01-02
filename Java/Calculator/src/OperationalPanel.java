import java.awt.Font;
import java.awt.GridLayout;

import javax.swing.*;

public class OperationalPanel extends JPanel{
	OperationalPanel(){
		GridLayout layout = new GridLayout(5, 1);
		setLayout(layout);
		Font font = new Font("Serif", Font.BOLD, 66);

		JButton plusButton = new JButton("+");
		plusButton.setFont(font);
		super.add(plusButton);
		
		JButton minusButton = new JButton("-");
		minusButton.setFont(font);
		super.add(minusButton);
	
		JButton multiplyButton = new JButton("*");
		multiplyButton.setFont(font);
		super.add(multiplyButton);
		
		JButton devideButton = new JButton("/");
		devideButton.setFont(font);
		super.add(devideButton);
		
		JButton equalToButton = new JButton("=");
		equalToButton.setFont(font);
		super.add(equalToButton);
		
	}
}