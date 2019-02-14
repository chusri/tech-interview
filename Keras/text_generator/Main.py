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
    training_data = text_generator.load_training_data()
    print training_data[:200]

if __name__ == '__main__':
    main()
