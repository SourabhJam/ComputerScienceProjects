import java.awt.Color;
import java.awt.Graphics;

public class Disc {
	int discSize;
	
	
	public Disc(int discSize) {
		this.discSize = discSize;
	}
	
	public void draw(Graphics g) {
		for(int i=discSize;i>0;i--) {
			g.setColor(Color.red);
		    g.fillRect(10,10,100,100);
		}
		System.out.println("");
	}

}
