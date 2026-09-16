public class Codec {

    private Map<String, String> map = new HashMap<>();
    private int id = 0;

    public String encode(String longUrl) {
        String shortUrl = "http://tinyurl.com/" + id;
        map.put(shortUrl, longUrl);
        id++;

        return shortUrl;
    }

    public String decode(String shortUrl) {
        return map.get(shortUrl);
    }
}