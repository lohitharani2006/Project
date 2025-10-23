import java.util.ArrayList;
import java.util.Scanner;

public class AttendanceSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> students = new ArrayList<>();

        while (true) {
            System.out.println("\n=== Attendance Management System ===");
            System.out.println("1. Add Student");
            System.out.println("2. Mark Attendance");
            System.out.println("3. View Attendance Report");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter student ID: ");
                    int id = sc.nextInt();
                    sc.nextLine(); // consume newline
                    System.out.print("Enter student name: ");
                    String name = sc.nextLine();
                    students.add(new Student(id, name));
                    System.out.println("Student added successfully!");
                    break;

                case 2:
                    if (students.isEmpty()) {
                        System.out.println("No students found!");
                        break;
                    }
                    System.out.println("\nMark attendance for today:");
                    for (Student s : students) {
                        System.out.print("Is " + s.name + " present? (y/n): ");
                        char status = sc.next().charAt(0);
                        s.markAttendance(status == 'y' || status == 'Y');
                    }
                    System.out.println("Attendance marked for all students!");
                    break;

                case 3:
                    System.out.println("\n=== Attendance Report ===");
                    System.out.printf("%-10s %-15s %-15s %-15s %-10s\n",
                            "ID", "Name", "Total Days", "Present Days", "Percent");
                    for (Student s : students) {
                        System.out.printf("%-10d %-15s %-15d %-15d %-10.2f%%\n",
                                s.id, s.name, s.totalDays, s.presentDays, s.getAttendancePercentage());
                    }
                    break;

                case 4:
                    System.out.println("Exiting... Thank you!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }
}
