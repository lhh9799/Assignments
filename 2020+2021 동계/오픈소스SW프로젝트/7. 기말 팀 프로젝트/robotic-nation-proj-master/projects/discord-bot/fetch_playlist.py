from spotipy.oauth2 import SpotifyClientCredentials
import spotipy
import pprint
import sys

def fetch(artist_name) :
    client_id = "395b486fb85a4b29a027ae3cc8c549d6"    #YOUR_CLIENT_ID
    client_secret = "cfb9f2ce0e33459095471eaaa872a86a"    #YOUR_CLIENT_SECRET

    import dbQuery as query
    lz_uri = query.RETRIEVE_FOR_DISCORD(artist_name)
    if lz_uri == 'N/A' :
        print("Exiting..")
        sys.exit()

    client_credentials_manager = SpotifyClientCredentials(client_id=client_id, client_secret=client_secret)
    sp = spotipy.Spotify(client_credentials_manager=client_credentials_manager)

    results = sp.artist_top_tracks(lz_uri)

    playlist = list()

    # get top 3 tracks
    for track in results['tracks'][:3]:
        playlist.append(track['name'])
    return playlist