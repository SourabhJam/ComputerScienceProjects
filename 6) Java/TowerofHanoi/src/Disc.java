
public class Disc {
	int discSize;
	
	public Disc(int discSize) {
		this.discSize = discSize;
	}
	
	public void draw() {
		for(int i=discSize;i>0;i--) {
			System.out.print("-");
		}
		System.out.println("");
	}

}
