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
    X, Y = text_generator._prepare_training_data()
    print X.shape
    print Y.shape
    print X[9000]
    print Y[9000]
    print text_generator.vocab_size
    print text_generator.sequence_length

    model = text_generator._create_model()
    print model.summary()

if __name__ == '__main__':
    main()
