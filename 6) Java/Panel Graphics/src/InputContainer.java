import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class InputContainer extends JFrame {

	JButton submitButton = new JButton("Submit");
	
	String fromText = "";
	JTextField from = new JTextField(fromText, 1);
	
	String toText = "";
	JTextField to = new JTextField(toText, 1);
	InputSubmitAction listener;
	
	InputContainer(InputSubmitAction listener){
		this.listener = listener;
	}
	
	public void draw(JPanel masterContainer) {
		JPanel inputContainer = new JPanel(new GridLayout(1, 3));
		masterContainer.add(inputContainer);

	
		Font bigFont = from.getFont().deriveFont(Font.PLAIN, 120f);
		from.setFont(bigFont);
		inputContainer.add(from);

	
		to.setFont(bigFont);
		inputContainer.add(to);

		submitButton.setFont(bigFont);
		inputContainer.add(submitButton);
		this.onSubmit();
	}

	public void onSubmit() {
		submitButton.addActionListener(new ActionListener() { 
			  public void actionPerformed(ActionEvent e) { 
				  String fromText = from.getText();
				  int fromNum = Integer.parseInt(fromText);
				  
				  String toText = to.getText();
				  int toNum = Integer.parseInt(toText);
				  
				  
				  try {
					listener.onSubmit(fromNum,toNum);
				} catch (Exception e1) {
					JLabel label = new JLabel(e1.getMessage());
					label.setFont(new Font("Arial", Font.BOLD, 38));
					JOptionPane.showMessageDialog(null,label,"ERROR",JOptionPane.WARNING_MESSAGE);
				}
				  
			  } 
			} );
	}

}
