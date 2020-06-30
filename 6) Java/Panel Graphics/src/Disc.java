import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class Disc {

	Color color;
	int discWidth;
	public Disc(Color color, int discWidth){
		this.color = color;
		this.discWidth = discWidth;
	}
	
	protected void draw(Graphics g, int referenceX, int towerBaseWidth, int yPos ) {
		g.setColor(this.color); 
		g.fillRect(referenceX+((towerBaseWidth/2)-(discWidth/2)), yPos, discWidth, 20);
	}
	
	public int getDiscWidth() {
		return discWidth; //returning discWidths for other classes to get information
	}
}
