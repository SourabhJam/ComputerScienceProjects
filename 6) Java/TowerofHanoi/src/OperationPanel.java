import java.awt.Font;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JPanel;

public class OperationPanel extends JPanel {
	OperationPanel() {
		GridLayout layout = new GridLayout(1, 3);
		setLayout(layout);
		Font font = new Font("Serif", Font.BOLD, 66);

		JButton fromButton = new JButton("From");
		fromButton.setFont(font);
		super.add(fromButton);

		JButton toButton = new JButton("To");
		toButton.setFont(font);
		super.add(toButton);

		JButton extraButton = new JButton("---------");
		extraButton.setFont(font);
		super.add(extraButton);

	}
}
