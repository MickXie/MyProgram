package ntou.cs.java2026;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;

public class BookParser {

    public Book parse(String bookName) throws IOException {
        // Convert spaces to underscores for the Wikipedia URL
        String formattedName = bookName.replace(" ", "_");
        String url = "https://en.wikipedia.org/wiki/" + formattedName;

        Document doc = Jsoup.connect(url).get();

        // 1. Extract Title
        String title = doc.select("#firstHeading").text();

        // 2. Locate the Infobox
        Element infoBox = doc.select(".infobox.vcard").first();
        if (infoBox == null) {
            throw new IOException("Unable to find the Infobox for: " + bookName);
        }

        // 3. Extract Author
        String author = getInfoBoxValue(infoBox, "Author");

        // 4. Extract Publisher
        String publisher = getInfoBoxValue(infoBox, "Publisher");

        // 5. Extract Publication Date (Try both common labels)
        String pubDate = getInfoBoxValue(infoBox, "Published");
        if (pubDate.equals("N/A")) {
            pubDate = getInfoBoxValue(infoBox, "Publication date");
        }

        // 6. Extract Summary (Find the first non-empty paragraph in the lead section)
        String summary = "No summary available.";
        Elements paragraphs = doc.select("#mw-content-text .mw-parser-output > p");

        for (Element p : paragraphs) {
            String text = p.text().trim();
            if (!text.isEmpty()) {
                summary = text;
                break;
            }
        }

        return new Book(title, author, publisher, pubDate, summary);
    }

    /**
     * Helper method using traditional Jsoup selection to find data by label.
     */
    private String getInfoBoxValue(Element infoBox, String label) {
        // Find the <th> tag that contains the specific label text
        Element header = infoBox.select("th:contains(" + label + ")").first();

        if (header != null) {
            Element data = header.nextElementSibling();
            if (data != null) {
                return data.text();
            }
        }
        return "N/A";
    }
}