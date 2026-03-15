package ntou.cs.java2026;

public class Book {
    private String title;
    private String author;
    private String publisher;
    private String publicationDate;
    private String plotSummary;

    public Book(String title, String author, String publisher, String publicationDate, String plotSummary) {
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.publicationDate = publicationDate;
        this.plotSummary = plotSummary;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public String getPublisher() {
        return publisher;
    }

    public String getPublicationDate() {
        return publicationDate;
    }

    public String getPlotSummary() {
        return plotSummary;
    }
}