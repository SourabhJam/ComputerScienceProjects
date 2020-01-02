import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JPanel;
import java.util.ArrayList;

public class TowerPanel extends JPanel {

	ArrayList<Disc> discs = new ArrayList<Disc>();

	public void draw(Graphics g) {

			g.drawRect(100, 10, 30, 40);
		// for (int i = 0; i < discs.size(); i++) {
		// Disc d = this.discs.get(i);
		// .draw(g);
	}

	public void addDisc(Disc disc) {
		this.discs.add(disc);
	}

	public Disc removeDisc() throws Exception {
		this.validateDisc();
		Disc disc = this.discs.remove(0);
		return disc;
	}

	private void validateDisc() throws Exception {
		if (discs.size() == 0) {
			throw new Exception("No Discs Avaliable");
		}

	}
}
