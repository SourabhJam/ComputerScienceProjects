import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Gamer implements InputSubmitAction{
	
	TowerContainer towercon;

	public void create() {
		JFrame frame = new JFrame();
		frame.setTitle("");
		frame.setSize(1500, 1500); //creating frame thats 1500x1500

		JPanel masterContainer = new JPanel(new GridLayout(2, 1)); //container that is 2x1

		towercon = new TowerContainer();
		towercon.create();
		masterContainer.add(towercon); //creating our tower container and adding it to the master

		InputContainer inputcon = new InputContainer(this);
		inputcon.draw(masterContainer); //creating our input container and adding it to the master

		frame.add(masterContainer);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //setting frame visible and closing when prompted

	}

	@Override
	public void onSubmit(int from, int to) throws Exception {
		System.out.println("from: " + from + " to=" + to);
		towercon.moveDics(from, to); //printing from tower and to tower when submitted
		
	}
	
	
}
