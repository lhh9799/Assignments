package prac07_06;
import java.util.*;

class Location {
	private String city;
	private double longitude, latitude;
	
	public Location(String city, double longitude, double latitude) {
		this.city = city;
		this.longitude = longitude;
		this.latitude = latitude;
	}
	public void printLocation() {
		System.out.print(city + "\t" + longitude + "\t" + latitude + "\n");
	}
}

class LocationManager {
	Scanner scanner = new Scanner(System.in);
	HashMap<String, Location> dept = new HashMap<String, Location>();
	
	private void read() {
		System.out.print("도시,경도,위도를 입력하세요.\n");
		for(int i=0; i<4; i++) {
			System.out.print(">>");
			String text = scanner.nextLine();
			StringTokenizer st = new StringTokenizer(text, ",");
			String city = st.nextToken().trim();
			String log = st.nextToken().trim();
			String lat = st.nextToken().trim();
			double longitude = Double.parseDouble(log);
			double latitude = Double.parseDouble(lat);
			
			Location loc = new Location(city, longitude, latitude);
			dept.put(city, loc);
		}
	}
	private void printAll() {
		Set<String> keys = dept.keySet();
		Iterator<String> it = keys.iterator();
		System.out.print("---------------------------\n");
		while(it.hasNext()) {
			String city = it.next();
			Location loc = dept.get(city);
			//System.out.println(city, loc);
			loc.printLocation();
		}
		System.out.print("---------------------------\n");
	}
	private void processQuery() {
		while(true) {
			System.out.print("도시 이름 >> ");
			String city = scanner.nextLine();
			if(city.equals("그만"))
				return;
			Location loc = dept.get(city);
			if(loc == null)
				System.out.print(city + "는 없습니다.\n");
			else
				loc.printLocation();
		}
	}
	public void run() {
		read();
		printAll();
		processQuery();
	}
}

public class LocationApp_20164269 {
	public static void main(String[] args) {
		LocationManager man = new LocationManager();
		man.run();
	}
}