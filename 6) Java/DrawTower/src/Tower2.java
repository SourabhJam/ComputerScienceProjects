import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JPanel;

class Tower2 extends JPanel {
	ArrayList<Disc> discs = new ArrayList<Disc>();

	private int towerBaseWidth;

	int poleDistanceFromWall = 50;
	int poleXPos;
	int poleYPos;
	int poleWidth;
	int poleHeight;
	int baseXPos;
	int baseYPos;
	int discXPos;
	int discYPos;
	int discOrigin;

	public Tower2() {
		towerBaseWidth = 400;
		this.poleXPos = 200;
		this.poleYPos = 100;
		this.poleWidth = 30;
		this.poleHeight = 400;
		this.baseXPos = 0;
		this.baseYPos = 500;
		this.discOrigin = towerBaseWidth + (poleWidth/2);

	}

	public void drawPole(Graphics g) {
		g.setColor(Color.red);
		g.fillRect(this.poleXPos, this.poleYPos, this.poleWidth, this.poleHeight);
	}

	public void drawBase(Graphics g) {
		g.fillRect(baseXPos, baseYPos, towerBaseWidth, 30);
	}

	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);
		this.drawPole(g);
		this.drawBase(g);
		
		int currentDiscYPos = baseYPos - 20;
		int currentDiscXPos = baseXPos + (towerBaseWidth/2);
		for (int i = 0; i < discs.size(); i++) {
			Disc d = this.discs.get(i);
			d.draw(g, currentDiscXPos, currentDiscYPos, discOrigin);
			currentDiscYPos = currentDiscYPos -20;
			
		}
	//	disc.draw(g, baseXPos + 70, baseYPos - 20);
	}
	
	public void addDisc(Disc disc) {
		this.discs.add(disc);
	}

	@Override
	public Dimension getPreferredSize() {
		return new Dimension(400, 400); // As suggested by camickr
	}
}