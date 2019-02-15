#!/home/ubuntu/wspace-2/anaconda2/bin/python

from TextGenerator import TextGenerator

def main():
    """
    Main thread of execution.

    Arguments:
    None

    Returns:
    None
    """

    text_generator = TextGenerator('republic.txt')

    training_data = text_generator._load_training_data()
    print training_data[:200]

    tokens = text_generator._tokenize_training_data(training_data)
    print tokens[:200]
    print 'Total tokens: %d' % len(tokens)
    print 'Unique tokens: %d' % len(set(tokens))

    sequences = text_generator._create_sequences(tokens)
    print sequences[9000]
    print len(sequences)

    encoded_sequences = text_generator._encode_sequences(sequences)
    print encoded_sequences[9000]
    print len(encoded_sequences)
    print len(encoded_sequences[9000])

    X, Y = text_generator._create_training_set(encoded_sequences)
    print X.shape
    print Y.shape
    print X[9000]
    print Y[9000]
    print text_generator.vocab_size
    print text_generator.sequence_length

if __name__ == '__main__':
    main()
