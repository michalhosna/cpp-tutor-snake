#!/usr/bin/env bash

# Dagmar Bártíková 2017
#
# Program reaguje na klíčová slova ve formě "medved" a "zajicek"


ZVIRE1=$1
ZVIRE2=$2

if [ "$#" -ne 2 ]; then
    echo "Potřebuji dvě zvířata"
    exit 1
fi

if [[ "${ZVIRE1}" = "medved" ]] || [[ "${ZVIRE2}" = "medved" ]]; then
    if [[ "${ZVIRE1}" = "${ZVIRE2}" ]]; then
        echo "Medvědi hrají kriket";
    elif [[ "${ZVIRE1}" = "zajicek" ]] || [[ "${ZVIRE2}" = "zajicek" ]]; then
        echo "Smůla medvěde";
    else
        echo "Medvěd je vítěz";
    fi
else
    if [[ "${ZVIRE1}" = "${ZVIRE2}" ]]; then
        echo "Nevím, kdo vyhraje";
    else
        echo "Nevím co se děje";
    fi
fi



# Řekněme, že je les, v něm žijou zvířátka a děsně rády hrají kriket.
# Medvěd je nejsilnější a vyhraje nad všemi zvířaty, mimo zajíčka.
# Hrají-li dvě stejná zvířata, hrají od úsvitu do soumraku a pak jdou na večeři...
#
# Připravte bash shell skript tak, že:
#    - Přijme dva parametry - první a druhé zvíře
#    - Vypíše odpověď v závislosti na tom o jaká zvířata jde
#
# Případy k rozlišení (na pořadí zvířat jako parametrů nezáleží):
#    - Medvěd a medvěd - "Medvědi hrají kriket"
#    - Medvěd a zajíček - "Smůla medvěde"
#    - Medvěd a jiné zvíře (ne medvěd, ne zajíček) - "Medvěd je vítěz"
#    - Dvě stejná zvířata (ne medvědi) - "Nevím, kdo vyhraje"
