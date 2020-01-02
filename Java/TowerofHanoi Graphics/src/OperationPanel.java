import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class OperationPanel extends JPanel {
	OperationPanel() {
		GridLayout layout = new GridLayout(1, 3);
		setLayout(layout);
		Font font = new Font("Serif", Font.BOLD, 66);

		JLabel fromLabel = new JLabel("From");
		fromLabel.setFont(font);
		super.add(fromLabel);

		JTextField fromtextField = new JTextField();
		fromtextField.setBounds(5, 5, 5, 5);
		fromtextField.setFont(font);
		super.add(fromtextField);

		JLabel toLabel = new JLabel("To");
		toLabel.setFont(font);
		super.add(toLabel);

		JTextField totextField = new JTextField();
		totextField.setBounds(5, 5, 5, 5);
		totextField.setFont(font);
		super.add(totextField);

		JButton submitButton = new JButton("Submit");
		submitButton.setFont(font);
		super.add(submitButton);


	
	// JButton button = new JButton("Do Something");
		submitButton.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			String userInputFrom = fromtextField.getText();
			double numFrom = Double.parseDouble(userInputFrom);
			
			String userInputTo = totextField.getText();
			double numTo = Double.parseDouble(userInputTo);
			
			
			JOptionPane.showMessageDialog(submitButton, "Number One: " + numFrom + "Number Two: " + numTo );
		}
	});
}

}
