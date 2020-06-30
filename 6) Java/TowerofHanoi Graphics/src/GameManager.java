import java.awt.Component;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JPanel;

public class GameManager extends JPanel {
	ArrayList<TowerPanel> towers = new ArrayList<TowerPanel>();

	public GameManager() {
		Disc smallDisc = new Disc(6);
		Disc mediumDisc = new Disc(10);
		Disc largeDisc = new Disc(20);

		TowerPanel tower1 = new TowerPanel();
		TowerPanel tower2 = new TowerPanel();
		TowerPanel tower3 = new TowerPanel();

		towers.add(tower1);
		towers.add(tower2);
		towers.add(tower3);

		tower1.addDisc(smallDisc);
		tower1.addDisc(mediumDisc);
		tower1.addDisc(largeDisc);
	}

	public void draw(Graphics g) {

		for (int i = 0; i < towers.size(); i++) {
			TowerPanel t = this.towers.get(i);
			System.out.println("Tower " + (i + 1));
			t.draw(g);
		}

	}

}
