import java.awt.Color;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Application {
	public static void main(String[] args) {
		
		JFrame f = new JFrame();
		f.setTitle("");
		f.setSize(1500, 1500);
		
		Tower tower1 = new Tower();
		
		f.add(tower1);
		
		Disc disc = new Disc(Color.black,300);
		Disc disc1 = new Disc(Color.blue,200);
		Disc disc2 = new Disc(Color.green,100);
		
		tower1.addDisc(disc);
		tower1.addDisc(disc1);
		tower1.addDisc(disc2);
		
	
		


		//GridLayout layout = new GridLayout(1, 1);
		//f.setLayout(layout);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}

}
