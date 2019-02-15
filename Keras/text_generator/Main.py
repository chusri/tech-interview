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

    sequence_file = text_generator._serialize_sequences(sequences)
    print sequence_file

if __name__ == '__main__':
    main()
