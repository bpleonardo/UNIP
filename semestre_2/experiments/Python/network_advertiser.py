import sys
import time
import socket
import logging
import argparse
import traceback

log = logging.Logger('network_advertiser')

MAGIC_NUMBER = b'PM02PENS\x00'


def get_socket(ip: str):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    sock.bind((ip, 0))
    return sock


def gen_packet(ip: str, port: int):
    data = MAGIC_NUMBER
    data += socket.inet_aton(ip)
    data += port.to_bytes(2, 'big')
    return data


def main(options):
    broadcast_port = options.broadcast_port
    port = options.port

    ip_addresses = tuple(socket.gethostbyname_ex(socket.gethostname())[-1])
    sockets = {ip: get_socket(ip) for ip in ip_addresses}

    log.info(
        'Advertising port %d on ip addresses "%s" on broadcast port %d every 2 seconds.',
        port,
        ', '.join(ip_addresses),
        broadcast_port,
    )

    try:
        while True:
            for ip, sock in sockets.items():
                sock.sendto(gen_packet(ip, port), ('<broadcast>', broadcast_port))
            time.sleep(2)
    except KeyboardInterrupt:
        pass
    except Exception:
        traceback.print_exc()
        return 1
    finally:
        for sock in sockets.values():
            sock.close()

    return 0


if __name__ == '__main__':
    parser = argparse.ArgumentParser('network_advertiser')

    parser.add_argument(
        '-b',
        '--broadcast-port',
        help='The port to broadcast to. Default 55009.',
        default=55009,
    )
    parser.add_argument(
        '-p',
        '--port',
        type=int,
        required=True,
        help='Port of the service being advertised.',
    )

    options = parser.parse_args()

    log.addHandler(logging.StreamHandler())

    sys.exit(main(options))
