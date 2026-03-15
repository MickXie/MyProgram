package ntou.cs.java2026;

public class BookParserTest {
    public static void main(String[] args) {
        String bookName = "The Mythical Man-Month";
        BookParser parser = new BookParser();

        try {
            Book book = parser.parse(bookName);

            System.out.println("Book Info:");
            System.out.println("Title: " + book.getTitle());
            System.out.println("Author: " + book.getAuthor());
            System.out.println("Publisher: " + book.getPublisher());
            System.out.println("Publication Date: " + book.getPublicationDate());
            System.out.println("Plot Summary: " + book.getPlotSummary());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}