
def extract(query, prefix=""):
    """extract takes in a `query` API function (which returns the first 5 usernames, lexicographically sorted,
    that start with a prefix) and returns the sorted list of all usernames in the database.
    For example, the `query` function in provided in `main` works as follows:

    query("a") #=> ["abracadara", "al", "alice", "alicia", "allen"]
    query("ab") #=> ["abracadara"]
    The following implementation would pass the assertion in `main`, but is not a correct solution since it
    works only for that example `query`:
    def extract(query):
        return query("ab") + query("al") + query("altercation") + query("b") + query("el") + query("ev") + query("m")
    Your goal is to write an `extract` method that is correct for any provided `query`.
    """
    # YOUR CODE HERE
    max = 5
    db = []
    abc = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

    for x in abc:
      results = query(prefix + x)
      if len(results) < max:
        if len(results) > 0:
          db += results
      else:
        #handle edge case where the first result matches exactly the next extract
        if results[0] == prefix + x:
          db += [results[0]]
        db += extract(query, prefix + x)

    return db

def main():
    """Runs your solution -- no need to update (except to maybe try out different databases)."""
    # Sample implementation of the autocomplete API
    database = ["abracadara", "al", "alice", "alicia", "allen", "alter", "altercation", "bob", "element", "ello", "eve", "evening", "event", "eventually", "mallory"]
    query = lambda prefix: [d for d in database if d.startswith(prefix)][:5]
    # print database
    # print extract(query)
    assert extract(query) == database

main()
