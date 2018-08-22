import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positive = []
        self.negative = []

        with open(positives, "r") as file_pos:
            for line in file_pos:
                if not line.startswith(';') and not line.startswith(' '):
                    token = line.strip()
                    self.positive.append(token)

        with open(negatives, "r") as file_neg:
            for line in file_neg:
                if not line.startswith(';') and not line.startswith(' '):
                    token = line.strip()
                    self.negative.append(token)


    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        pos = 0
        neg = 0

        tknzr = nltk.tokenize.TweetTokenizer()
        tokens = tknzr.tokenize(text)

        for tkn in tokens:
            if tkn in self.positive:
                pos += 1
            elif tkn in self.negative:
                neg += 1

        result = pos - neg
        return result