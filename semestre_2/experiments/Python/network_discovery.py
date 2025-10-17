import sys
import select
import socket
import logging
import argparse
import traceback

log = logging.Logger('network_discovery')

MAGIC_NUMBER = b'PM02PENS\x00'


def main(options):
    broadcast_port = options.broadcast_port

    log.info('Listening on broadcast port %d.', broadcast_port)

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(('', broadcast_port))  # Listen on all interfaces.

    try:
        while True:
            ready = select.select(
                [sock], [], [], 1
            )  # Wait until read for read or timeout.
            if ready[0]:
                data = sock.recv(16)  # wait for a packet
                log.info('Received data 0x%s.', data.hex())

                if data.startswith(MAGIC_NUMBER):
                    offset = len(MAGIC_NUMBER)
                    try:
                        ip = socket.inet_ntoa(data[offset : offset + 4])
                        port = int.from_bytes(data[offset + 4 :], 'big')
                    except Exception:
                        log.exception('Could not decode it.')
                        continue

                    log.info('Decoded to be "%s:%d".', ip, port)

                    print(f'{ip}:{port}')

                    if options.exit_if_found:
                        break
    except KeyboardInterrupt:
        pass
    except Exception:
        traceback.print_exc()
        return 1
    finally:
        sock.close()

    return 0


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        'network_discovery',
        description='Tries to find a service matching the MAGIC_NUMBER on the local network.',
    )

    parser.add_argument(
        '-b',
        '--broadcast-port',
        help='The port to broadcast to. Default 55009.',
        default=55009,
    )
    parser.add_argument(
        '-x',
        '--exit-if-found',
        help='Exit the program when the first service is found.',
        default=True,
    )
    options = parser.parse_args()

    log.addHandler(logging.StreamHandler())

    sys.exit(main(options))
