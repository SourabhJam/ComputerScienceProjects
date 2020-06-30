
public class Student {
	int gradeLevel;
	String name;
	
	Student(int selectGradeLevel){
		gradeLevel = selectGradeLevel;
	}
	
	Student(String inputName){
		name = inputName;
		computeScore();
	}
	
	Student(String inputName,int selectGradeLevel){
		name = inputName;
		gradeLevel = selectGradeLevel;
	}
	
	void displayStudentInfo(){
        System.out.println(name + " is currently enrolled in grade level " + gradeLevel );
    }
	
	private void computeScore(){
		System.out.println("Computing Scores");
	}
}
