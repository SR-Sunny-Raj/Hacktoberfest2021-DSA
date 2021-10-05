class StringReverse {
  public static void main(String[] args) {

    // Given a string "ExampleString", we need to resolve problem fetch all the
    // elements of string and do iterable reverse from lastest characters until
    // first characters
    // output: gnirtSelpmaxE

    // First Solutions
    // Using with bytes
    String normalString = "ExampleString";

    byte[] normalBytes = normalString.getBytes();

    byte[] reverse = new byte[normalBytes.length];

    for (int i = 0; i < normalBytes.length; i++) {
      reverse[i] = normalBytes[normalBytes.length - i - 1];
    }

    System.out.println(new String(reverse));

    // Second Solution
    // Using class StringBuilder
    System.out.println(new StringBuilder("ExampleString").reverse().toString());

  }
}
