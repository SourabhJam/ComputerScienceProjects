package pics;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class Disc extends JPanel{
	
	
	protected void paintComponent(Graphics g) {
		g.setColor(Color.blue);
		g.fillRect(100,100,100,100);
		
		super.paintComponent(g);
	}
}
