import java.util.ArrayList;

public class GameManager {
	ArrayList<Tower> towers = new ArrayList<Tower>();

	public GameManager() {
		Disc smallDisc = new Disc(6);
		Disc mediumDisc = new Disc(10);
		Disc largeDisc = new Disc(20);

		Tower tower1 = new Tower();
		Tower tower2 = new Tower();
		Tower tower3 = new Tower();

		towers.add(tower1);
		towers.add(tower2);
		towers.add(tower3);

		tower1.addDisc(smallDisc);
		tower1.addDisc(mediumDisc);
		tower1.addDisc(largeDisc);
	}

	public void draw() {

		for (int i = 0; i < towers.size(); i++) {
			Tower t = this.towers.get(i);
			System.out.println("Tower " + (i + 1));
			t.draw();
		}

	}

	public void move(int from, int to) throws Exception {
		this.validateTower(from,to);
		Disc disc = towers.get(from).removeDisc();
		towers.get(to).addDisc(disc);

		this.draw();
	}

	private void validateTower(int from, int to) throws Exception {
		if (from < 0 || from > 3) {
			throw new Exception("From Has To Be Between 1 and 3");
		}else if(to<0||to>3) {
			throw new Exception("To Has To Be Between 1 and 3");
		}

	}
	
	
}
