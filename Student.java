public class Student {
    int id;
    String name;
    int totalDays;
    int presentDays;

    public Student(int id, String name) {
        this.id = id;
        this.name = name;
        this.totalDays = 0;
        this.presentDays = 0;
    }

    public void markAttendance(boolean isPresent) {
        totalDays++;
        if (isPresent) presentDays++;
    }

    public double getAttendancePercentage() {
        if (totalDays == 0) return 0;
        return (presentDays * 100.0) / totalDays;
    }
}