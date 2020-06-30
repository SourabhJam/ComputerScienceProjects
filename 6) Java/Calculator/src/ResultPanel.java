import java.awt.Font;

import javax.swing.*;
public class ResultPanel extends JPanel{

	JTextField textField;
	
	ResultPanel(){
		
		textField = new JTextField();
		textField.setText("          ");
		Font font = new Font("Serif", Font.BOLD, 66);
		textField.setFont(font);
				
		super.add(textField);
	}
	
	public void setNumber(String number) {
		// set the number in text field.
		this.textField.setText(number);
	}
}
 