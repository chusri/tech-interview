import PhoneBook

def main():
    pb = PhoneBook.PhoneBook()

    pb.add('Nawab Ali', 5034709584)
    print(pb.find_number('Nawab Ali'))
    print(pb.find_name(5034709584))

    print(pb.find_number('Ali'))
    print(pb.find_name(503709584))

    pb.delete_name('Amelia Johnson')
    pb.delete_number(3602017244)

    pb.delete_number(5034709584)
    print(pb.find_name(5034709584))

if __name__ == '__main__':
    main()
