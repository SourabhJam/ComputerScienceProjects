import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.util.ArrayList;

import javax.swing.JLabel;
import javax.swing.JPanel;

public class TowerContainer extends JPanel {
	ArrayList<Tower> towers = new ArrayList<Tower>();

	public void create() {

		this.setLayout(new GridLayout(1, 3));

		Tower tower1 = new Tower();
		Disc disc1 = new Disc(Color.blue, 200);
		Disc disc2 = new Disc(Color.green, 100);
		Disc disc = new Disc(Color.black, 300);

		tower1.addDisc(disc);
		tower1.addDisc(disc1);
		tower1.addDisc(disc2);
		tower1.setPreferredSize(new Dimension(100, 100));
		this.add(tower1);
		towers.add(tower1);

		Tower tower2 = new Tower();
		tower2.setPreferredSize(new Dimension(100, 100));
		this.add(tower2);
		towers.add(tower2);

		Tower tower3 = new Tower();
		tower3.setPreferredSize(new Dimension(100, 100));
		this.add(tower3);
		towers.add(tower3);

	}

	public void moveDics(int from, int to) throws Exception {

		int userFrom = from - 1;
		int userTo = to - 1;

		this.validateTower(userFrom, userTo);
		Disc disc = towers.get(userFrom).removeDisc();
		Tower toTower = towers.get(userTo);
		Tower fromTower = towers.get(userFrom);

		Boolean isAllowed = toTower.isDiscAllowed(disc);

		if (isAllowed == true) {
			toTower.addDisc(disc);
			this.repaintAll();

		} else {
			fromTower.addDisc(disc);
			throw new Exception("Not Allowed");
		}

		Tower lastTower = towers.get(towers.size() - 1);
		if (lastTower.isFull() == true) {
			System.out.println("Game Over!");
		}
	}

	private void validateTower(int from, int to) throws Exception {
		if (from < 0 || from > 3) {
			throw new Exception("From Has To Be Between 1 and 3");
		} else if (to < 0 || to > 3) {
			throw new Exception("To Has To Be Between 1 and 3");
		}

	}

	private void repaintAll() {
		for (int i = 0; i < towers.size(); i++) {
			Tower t = this.towers.get(i);
			t.revalidate();
			t.repaint();

		}

	}
}
