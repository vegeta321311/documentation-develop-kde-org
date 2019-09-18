import requests
from sphinx.util.console import bold


_DOXYLINK = {
    'kirigamiapi' : ('Kirigami2.tags', 'https://api.kde.org/frameworks/kirigami/html/'), # https://api.kde.org/frameworks/kirigami/html/Kirigami2.tags
    'kwidgetsaddonsapi' : ('KWidgetsAddons.tags', 'https://api.kde.org/frameworks/kwidgetsaddons/html/'), # https://api.kde.org/frameworks/kwidgetsaddons/html/KWidgetsAddons.tags
    'plasmaapi' : ('Plasma.tags', 'https://api.kde.org/frameworks/plasma-framework/html/') # https://api.kde.org/frameworks/plasma-framework/html/Plasma.tags
}


def _download_doxylink(base_url, filename):
    url = base_url + '/' + filename
    print(bold("Downloading file {} to {}".format(url, filename)))
    response = requests.get(url)
    if response.status_code != 200:
        raise Exception('{} HTTP response received from {}'
                        .format(response.status_code, url))
    with open('../' + filename, "w") as tagFile:
        tagFile.write(response.text)


def get_doxylink():
    for doc in _DOXYLINK.values():
        _download_doxylink(doc[1], doc[0])
    return _DOXYLINK
