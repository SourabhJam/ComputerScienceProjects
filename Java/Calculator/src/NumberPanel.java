import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class NumberPanel extends JPanel implements ActionListener {
	
	ResultPanel resultPanel;
	
	NumberPanel(ResultPanel resultPanel){
		
		
		this.resultPanel = resultPanel;
		GridLayout numberPanelLayout = new GridLayout(4, 3);
		setLayout(numberPanelLayout);
		
		for(int i=0; i<10; i++) {
			String buttonText = Integer.toString(i);
			JButton numberButton = new JButton();
			Font font = new Font("Serif", Font.BOLD, 66);
			numberButton.setFont(font);
			numberButton.setText(buttonText);
			
			add(numberButton); 
			numberButton.addActionListener(this);
			
			ButtonInformer buttonInformer = new ButtonInformer();
			numberButton.addActionListener(buttonInformer);
			
		}
	}
	
	public void actionPerformed(ActionEvent e) {
		String buttonText = e.getActionCommand();
		this.resultPanel.setNumber(buttonText);
	}
}