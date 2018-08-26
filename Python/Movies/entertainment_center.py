import media
import fresh_tomatoes

def create_movies():
    toy_story = media.Movie('Toy Story',
                            'A story of a boy and his toys that come to life.',
                            'https://upload.wikimedia.org/wikipedia/en/1/13/Toy_Story.jpg',
                            'https://www.youtube.com/watch?v=4KPTXpQehio')

    avatar = media.Movie('Avatar',
                         'A marine on an alien planet.',
                         'https://upload.wikimedia.org/wikipedia/en/b/b0/Avatar-Teaser-Poster.jpg',
                         'https://www.youtube.com/watch?v=5PSNL1qE6VY')

    school_of_rock = media.Movie('School of Rock',
                                 'Using Rock music to learn.',
                                 'https://upload.wikimedia.org/wikipedia/en/1/11/School_of_Rock_Poster.jpg',
                                 'https://www.youtube.com/watch?v=5afGGGsxvEA')

    ratatouille = media.Movie('Ratatouille',
                              'A rat is a chef in Paris.',
                              'https://upload.wikimedia.org/wikipedia/en/5/50/RatatouillePoster.jpg',
                              'https://www.youtube.com/watch?v=PeFGdSrFTUw')

    midnight_in_paris = media.Movie('Midnight in Paris',
                                    'Going back in time to meet authors.',
                                    'https://upload.wikimedia.org/wikipedia/en/9/9f/Midnight_in_Paris_Poster.jpg',
                                    'https://www.youtube.com/watch?v=BYRWfS2s2v4')

    hunger_games = media.Movie('Hunger Games',
                               'A really real reality show.',
                               'https://upload.wikimedia.org/wikipedia/en/4/42/HungerGamesPoster.jpg',
                               'https://www.youtube.com/watch?v=mfmrPu43DF8')

    movies = [toy_story, avatar, school_of_rock, ratatouille, midnight_in_paris, hunger_games]
    return(movies)

def main():
    movies = create_movies()
    fresh_tomatoes.open_movies_page(movies)

if __name__ == '__main__':
    main()
