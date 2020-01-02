import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JPanel;

class Tower extends JPanel {
	ArrayList<Disc> discs = new ArrayList<Disc>();

	int referenceX;
	int referenceY;
	int towerBaseWidth;
	int poleWidth;
	int poleHeight;
	
	public Tower() {
		this.referenceX = 100;
		this.referenceY = 600;
		this.towerBaseWidth = 400;
		this.poleWidth = 30;
		this.poleHeight =300;
		

	}

	public void drawPole(Graphics g) {
		g.setColor(Color.red);
		g.fillRect(referenceX+((towerBaseWidth/2)-(poleWidth/2)), referenceY-300, this.poleWidth, this.poleHeight);
	}

	public void drawBase(Graphics g) {
		g.setColor(Color.red);
		g.fillRect(referenceX, referenceY, towerBaseWidth, 30);
	}

	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);
		this.drawPole(g);
		this.drawBase(g);
		
		int currentDiscYPos = referenceY - 20;
		int currentDiscXPos = referenceX + (towerBaseWidth/2);
		
		for (int i = 0; i < discs.size(); i++) {
			Disc d = this.discs.get(i);
			d.draw(g, referenceX, towerBaseWidth, currentDiscYPos);
			currentDiscYPos = currentDiscYPos -20;
			
		}
		
	}
	//	disc.draw(g, baseXPos + 70, baseYPos - 20);

	
	public void addDisc(Disc disc) {
		this.discs.add(disc);
	}

	@Override
	public Dimension getPreferredSize() {
		return new Dimension(400, 400); // As suggested by camickr
	}
}